from numpy import mean
from sklearn.datasets import make_classification
from sklearn.model_selection import LeaveOneOut
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LogisticRegression
from matplotlib import pyplot

def evaluate_model(cv):     # 평가 모델 함수 정의
    # 표본 데이터 수 = 100, 독립 변수의 수 = 20, informative 성분의 수 = 15로 
    # 가상의 분류모형 데이터를 생성합니다.
    X, y = make_classification(n_samples=100, n_features=20, n_informative=15, n_redundant=5, random_state=1)   # 데이터 분휴하기
    model = LogisticRegression()    # 로지스틱 회귀 진행
    scores = cross_val_score(model, X, y, scoring='accuracy', cv=cv, n_jobs=-1) # 교차 검증 진행
    return mean(scores), scores.min(),scores.max()  # 평균값 계산하여 리턴하기

ideal, _, _ = evaluate_model(LeaveOneOut()) # loocv 프로시저를 평가 모델 매개변수로 대입
print('Ideal: %.3f'% ideal) # 계산된 평균값 출력
folds = range(2,20) # 반복할 2~20 범위 지정
means, mins, maxs = list(), list(), list()  # list로정의

for k in folds: # 2~20까지 반복
    cv = KFold(n_splits=k, shuffle=True, random_state=1)    # 교차 검증 진행
    k_mean, k_min, k_max = evaluate_model(cv)   # 교차 검증된 cv로 평가 모델 진행
    print('> folds=%d, accuracy=%.3f (%.3f, %.3f)' % (k, k_mean, k_min, k_max)) # k에 대한 정확도 출력하기
    means.append(k_mean)    # 평균값 push
    mins.append(k_mean - k_min) # 평균 - 최솟값 push
    maxs.append(k_max - k_mean) # 최댓값 - 평균값 push

pyplot.errorbar(folds, means, yerr=[mins, maxs], fmt ='o')  # 최소/최대 에러바가 있는 k 평균 값의 선
pyplot.plot(folds, [ideal for _ in range(len(folds))], color='r')   # ideal case를 그래프로 나타내기
pyplot.show()  # 그래프 창 띄우기
