from cProfile import label
from distutils.log import Log
from turtle import pos
from sklearn.datasets import make_classification    # 분류하기 위한 패키지
from sklearn.model_selection import train_test_split

# 표본 데이터 수 = 1000, 클래스 수 = 2, 독립 변수의 수 = 2로
# 가상의 분류모형 데이터를 생성합니다.
X, y = make_classification(n_samples=1000, n_classes=2, n_features=20, random_state=27)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=27)   # 학습과 테스트 세트를 분리

from sklearn.linear_model import LogisticRegression # 로지스틱 회귀 패키지
model1 = LogisticRegression()   # 로지스틱 회귀 진행
model1.fit(X_train, y_train)    # 속성과 레이블을 fit
pred_prob1 = model1.predict_proba(X_test)   # 해당 레이블로 분류될 확률 값 구하기

from sklearn.metrics import roc_curve
fpr1, tpr1, thresh1 = roc_curve(y_test, pred_prob1[:,1], pos_label=1)   # 임계값에 따라 ROC 커브 위의 점 위치가 변함

random_probs = [0 for i in range(len(y_test))]  # tpr = fpr에 대한 roc 곡선(랜덤)
p_fpr, p_tpr, _ = roc_curve(y_test, random_probs, pos_label=1)  # roc 곡선 휨 정도 구하기

from sklearn.metrics import roc_auc_score   # 점수를 구하기 위한 패키지
auc_score1 = roc_auc_score(y_test, pred_prob1[:,1]) # 데이터 정답과 예측을 바로 auc로 구하기
print('AUC value : %s' %auc_score1) # 계산한 점수 출력하기

# plotting
import matplotlib.pyplot as plt # 그래프를 그리기 위한 패키지
plt.style.use('seaborn')    # seaborn style 사용
plt.plot(fpr1, tpr1, linestyle='--', color='orange', label='Logistic Regression')   # 색상이나 스타일, 라벨 정하기
plt.plot(p_fpr, p_tpr, linestyle='--', color='blue')    # 색상이나 스타일 정하기
plt.title('ROC curve')  # 제목 붙이기
plt.xlabel('False Positive Rate')   # x-label붙이기
plt.ylabel('True Positive rate')    # y-label붙이기

plt.legend(loc='best')  # 
plt.savefig('ROC', dpi=300) # 
plt.show()  # 그래프 창 띄우기
