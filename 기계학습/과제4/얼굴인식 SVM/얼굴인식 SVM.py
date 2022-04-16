from sklearn.datasets import fetch_lfw_people # 모듈 가져오기
from sklearn.svm import SVC
from sklearn.decomposition import PCA as RandomizedPCA
from sklearn.pipeline import make_pipeline
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split, GridSearchCV
import seaborn as sns
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix

faces = fetch_lfw_people(min_faces_per_person=60) # lfw_people 데이터불러오기
print(faces.target_names)   # 출력하기
print(faces.images.shape)   # 출력하기
Xtrain, Xtest, ytrain, ytest = train_test_split(faces.data, faces.target, random_state=0) # 학습, 테스트로 나누어 데이터 분리 

fig, ax = plt.subplots(3,5) # subplot 구하기
for i, axi in enumerate(ax.flat):   # ax를 flat한 값들을 반복
    axi.imshow(faces.images[i], cmap='bone')    # imshow
    axi.set(xticks=[], yticks=[],
            xlabel=faces.target_names[faces.target[i]]) # set

pca = RandomizedPCA(n_components=150, whiten=True, random_state=0) # 랜덤 PCA
svc = SVC(kernel='rbf', class_weight='balanced') # SVC 실행
model = make_pipeline(pca, svc) # 파이프라인 만들기

param_grid = {'svc__C':[1,5,10,50],'svc__gamma':[0.0001,0.0005,0.001,0.005]}    # 파라미터 grid 선언
grid = GridSearchCV(model, param_grid)  # 그리드 서치 CV실행
grid.fit(Xtrain,ytrain) # gird에 Xtrain, ytrain로 fit
print(grid.best_params_)   # 출력하기
model = grid.best_estimator_ # 그리드의 베스트 평가를 모델에 넣기
yfit = model.predict(Xtest) # Xtest 예측하여 yfit구하기


fig, ax = plt.subplots(4,6) # subplot 구하기
for i, axi in enumerate(ax.flat): # ax를 flat한 값들 반복
    axi.imshow(Xtest[i].reshape(62,47), cmap='bone') # imshow
    axi.set(xticks=[],yticks=[])    # set
    axi.set_ylabel(faces.target_names[yfit[i]].split()[-1],
                   color='black' if yfit[i] == ytest[i] else 'red') # axi값을 ylabel로 set
fig.suptitle('Predicted Names(Incorrect Labels in Red)', size=14) # suptitle지정
print(classification_report(ytest,yfit,target_names=faces.target_names))    # 출력하기
plt.show() # 그리기

mat = confusion_matrix(ytest, yfit) # 혼동행렬 구하기
sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
            xticklabels=faces.target_names, yticklabels=faces.target_names) # heatmap구하기
plt.xlabel('true label')    # X라벨
plt.ylabel('predicted label') # Y라벨
plt.show() # 창 띄우기

from sklearn.metrics import accuracy_score
print('정확도: ', accuracy_score(ytest,yfit))   # 정확도 출력하기