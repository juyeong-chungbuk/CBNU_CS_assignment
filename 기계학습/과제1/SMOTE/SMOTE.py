#SMOTE
from collections import Counter
from sklearn.datasets import make_classification
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.pipeline import Pipeline
from matplotlib import pyplot
from numpy import where

# 표본 데이터 수 = 10000, 독립 변수의 수 = 2, 클래스 당 클러스터의 수 = 1, 할당할 표본 수 = 0.99로 
# 가상의 분류모형 데이터를 생성합니다.
X, y = make_classification(n_samples=10000, n_features=2, n_redundant=0, n_clusters_per_class=1, weights=[0.99], flip_y=0, random_state=1)

counter = Counter(y)    # y를 딕셔너리 형태로 변환하여 개수를 추출하도록 합니다.
print('generated data: %s'% counter)    # 개수 출력하기

for label, _ in counter.items():    # 각각의 아이템별로 반복
    row_ix = where(y == label)[0]   # 클래스의 샘플에 대한 행 인덱스를 얻는다.
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label))    # 샘플의 산점도 그리기
pyplot.legend() # 그래프에 데이터 나타내기
pyplot.show() # 그래프 창 열기

over = SMOTE(sampling_strategy=0.1) # SMOTE 진행 (sampling_strategy=0.1)
X, y = over.fit_resample(X,y)   # over로 리샘플링
counter = Counter(y)    # y를 딕셔너리 형태로 변환하여 개수 추출
print('SMOTE-based oversampled data : %s'% counter)    # 개수 출력하기

for label, _ in counter.items():     # 각각의 아이템별로 반복
    row_ix = where(y == label)[0]   # 클래스의 샘플에 대한 행 인덱스를 얻는다.
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label))    # 샘플의 산점도 그리기
pyplot.legend() # 그래프에 데이터 나타내기
pyplot.show() # 그래프 창 열기