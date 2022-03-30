# multi-class classification
from matplotlib import pyplot as plt
from sklearn.datasets import make_classification
from sklearn.multiclass import OneVsRestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve
from sklearn.metrics import roc_auc_score

# 표본 데이터 수 = 1000, 클래스의 수 = 3, 독립 변수의 수 = 20, informative 성분의 수 = 3로 
# 가상의 분류모형 데이터를 생성합니다.
X, y = make_classification(n_samples=1000, n_classes=3, n_features=20,
                            n_informative=3, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4,
                                                    random_state=42)    # 학습 데이터와 테스트 데이터 세트를 분리
clf = OneVsRestClassifier(LogisticRegression()) # 로지스틱 회귀 모델을 생성하여 분류기 학습 진행
clf.fit(X_train, y_train)   # fit 시키기
pred = clf.predict(X_test)  # 테스트 결과 예측하기
pred_prob = clf.predict_proba(X_test)   # 체인의 확률값 계산하기

fpr = {}    # false positive rate
tpr = {}    # true positive rate
thresh = {} # 임계값
n_class = 3 # 클래스 개수 3
for i in range(n_class):    # 3개의 클래스 반복
    fpr[i], tpr[i], thresh[i] = roc_curve(y_test, pred_prob[:,i], pos_label=i)  # 클래스별로 roc곡선 그리기

plt.plot(fpr[0], tpr[0], linestyle='--', color='orange', label='Class 0 vs Rest')   # 그래프 생성
plt.plot(fpr[1], tpr[1], linestyle='--', color='green', label='Class 1 vs Rest')    # 그래프 생성
plt.plot(fpr[2], tpr[2], linestyle='--', color='blue', label='Class 2 vs Rest') # 그래프 생성
plt.title('Multiclass ROC curve')   # 제목 붙이기
plt.xlabel('False Positive Rate')   # x-label 붙이기
plt.ylabel('True Positive rate')   # y-label 붙이기
plt.legend(loc='best')  # 그래프에 데이터 나타내기
plt.savefig('Multiclass ROC', dpi=300)  # 그림 파일로 저장하기
plt.show()  # 그래프 창 띄우기