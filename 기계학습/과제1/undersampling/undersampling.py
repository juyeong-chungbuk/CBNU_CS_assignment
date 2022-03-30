# Random Undersampling
from collections import Counter
from sklearn.datasets import make_classification
from imblearn.over_sampling import SMOTE
from imblearn.under_sampling import RandomUnderSampler
from imblearn.pipeline import Pipeline
from matplotlib import pyplot
from numpy import where

# make_classification(): n_redundant (no. of redundant features)
#                        weights (portion of samples assigned to a class)
# 표본 데이터 수 = 10000, 독립 변수의 수 = 2, 클래스 당 클러스터의 수 = 1, 할당할 표본 수 = 0.99로 
# 가상의 분류모형 데이터를 생성합니다.
X, y = make_classification(n_samples=10000, n_features=2, n_redundant=0,
  n_clusters_per_class=1, weights=[0.99], flip_y=0, random_state=1)

# y를 딕셔너리 형태로 변환하여 개수를 추출하도록 합니다.
counter = Counter(y)
print('generated data: %s' % counter)   # 생성된 데이터의 개수를 출력
for label, _ in counter.items():    # 각각의 아이템별로 반복
    row_ix = where(y == label)[0]   # 클래스의 샘플에 대한 행 인덱스를 얻는다.
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label))    # 샘플의 산점도 그리기
pyplot.legend() # 그래프에 데이터 나타내기
pyplot.show() # 그래프 창 열기

# sampling_strategy : Iminority samples|/|Imajority saamples| after resampling
under = RandomUnderSampler(sampling_strategy=0.5)   # 무작위 언더 샘플링 진행
X, y = under.fit_resample(X, y) # 변형 적용하여 리샘플링
count = Counter(y)  # y를 딕셔너리 형태로 변환하여 개수를 추출하도록 합니다.
print('Undersampled data: %s' % counter)   # 생성된 데이터의 개수를 출력

for label, _ in counter.items():    # 각각의 아이템별로 반복
    row_ix = where(y == label)[0]   # 클래스의 샘플에 대한 행 인덱스를 얻는다.
    pyplot.scatter(X[row_ix, 0], X[row_ix, 1], label=str(label))    # 샘플의 산점도 그리기
pyplot.legend() # 그래프에 데이터 나타내기
pyplot.show() # 그래프 창 열기