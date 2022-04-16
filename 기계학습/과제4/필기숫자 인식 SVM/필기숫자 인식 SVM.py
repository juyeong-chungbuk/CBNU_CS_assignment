import matplotlib.pyplot as plt # 모듈 가져오기
from sklearn import datasets, svm, metrics
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split

digits = datasets.load_digits() # 데이터셋 로드
_, axes = plt.subplots(2, 5) # subplot값 2-5 추출하기
images_and_labels = list(zip(digits.images, digits.target)) # 이미지와 타겟으로 zip한 리스트 생성
for ax, (image, label) in zip(axes[0, :], images_and_labels[:5]):   # axes, 이미지와 라벨 zip을 반복
    ax.set_axis_off()   # axis를 off하기
    ax.imshow(image, cmap=plt.cm.gray_r, interpolation='nearest')   # imshow
    ax.set_title('Training: %i' % label) # title 지정하기

n_samples = len(digits.images) # 10진수 길이 = 샘플의 길이
data = digits.images.reshape((n_samples, -1))   # 이미지를 reshape

X_train, X_test, y_train, y_test = train_test_split(data, digits.target, test_size=0.5, shuffle=False)  # 학습, 테스트로 나누어 데이터 분리
classifier = svm.SVC(kernel='rbf', gamma=0.001)  # svm을 SVC실행하여 분류기에 넣기
classifier.fit(X_train, y_train)  # X_train, y_train으로 분류하기 fit

predicted = classifier.predict(X_test) # X_test로 예측하기

test_data = X_test.reshape((len(X_test), 8, 8)) # X_test값을 reshape한 값 = 테스트 데이터
images_and_predictions = list(zip(test_data, predicted)) # 테스트 데이터, 예측 zip을 리스트
for ax, (image, prediction) in zip(axes[1, :], images_and_predictions[:5]): # 이미지와 예측을 zip 반복
    ax.set_axis_off()   # axis를 off하기
    ax.imshow(image, cmap=plt.cm.gray_r, interpolation='nearest')   # imshow
    ax.set_title('Predict: %i' % prediction) # title 지정하기

print("SVM 분류 결과 %s:\n%s\n"
    % (classifier, metrics.classification_report(y_test, predicted)))   # 분류결과 출력하기
disp = metrics.plot_confusion_matrix(classifier, X_test, y_test) # 메트릭스의 혼동행렬 저장
disp.figure_.suptitle("Confusion Matrix") # suptitle지정
print("혼동 행렬: \n%s" % disp.confusion_matrix)    # 혼동행렬 출력하기
print("정확도 : ", accuracy_score(y_test, predicted))   # 정확도 출력하기

plt.show()