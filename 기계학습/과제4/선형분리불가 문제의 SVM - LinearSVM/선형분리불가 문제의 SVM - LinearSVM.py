import numpy as np # 모듈 가져오기
from sklearn.datasets import make_blobs
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt
from sklearn.svm import LinearSVC
from sklearn.metrics import confusion_matrix

X, y = make_blobs(n_samples=250, centers=2, random_state=0, cluster_std = 0.85) # 샘플 250개 centers 2개로 blob만들기
y[y == 0] = -1  # 0값을 -1로 변환
y = y.astype(float)
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0) # 학습, 테스트로 나누어 데이터 분리

svc = LinearSVC(C=0.5)  # 선형 SVC연산
svc.fit(X_train, y_train)   # svc에 X_train, y_train로 fit

y_pred = svc.predict(X_train) # X_train으로 예측
print('training data = \n', confusion_matrix(y_train, y_pred))  # 혼동 행렬 출력

y_pred = svc.predict(X_test) # X_train으로 예측
print('testing data = \n', confusion_matrix(y_test, y_pred))    # 혼동 행렬 출력

def f(x, w, b, c=0): # f함수
    return (-w[0] * x - b + c) / w[1] # 계산식

plt.scatter(X_train[:, 0], X_train[:, 1], c=y_train, cmap='winter') # 산점도 그리기
ax = plt.gca() # gca함수 실행
xlim = ax.get_xlim() # xlim을 가져오기
w = svc.coef_[0] # coef
a = -w[0] / w[1] # 기울기
xx = np.linspace(xlim[0], xlim[1])  # 막대선 그리기
yy = a * xx - svc.intercept_[0] / w[1]  # yy값 구하기
plt.plot(xx, yy) # plot 그리기
yy = a * xx - (svc.intercept_[0] - 1) / w[1] # yy값 구하기
plt.plot(xx, yy, 'k--') # plot 그리기
yy = a * xx - (svc.intercept_[0] + 1) / w[1] # yy값 구하기
plt.plot(xx, yy, 'k--') # plot 그리기
plt.xlim(-1, 4) # xlim 범위 지정
plt.title("Linear SVM") # 제목 설정
plt.show()  # 출력하기
