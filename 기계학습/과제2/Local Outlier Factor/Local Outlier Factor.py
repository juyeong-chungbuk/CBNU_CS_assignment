import numpy as np
import matplotlib.pyplot as plt
from sklearn.neighbors import LocalOutlierFactor

np.random.seed(42)  # 랜덤 시드 42
X_inliners = 0.3 * np.random.randn(100, 2) # 데이터 생성
X_inliners = np.r_[X_inliners + 2, X_inliners - 2]  # 오른쪽으로 배열 붙이기
X_outliers = np.random.uniform(low = -4, high = 4, size = (20, 2))  # 정규화 하기
X = np.r_[X_inliners, X_outliers]   # 오른쪽으로 배열 붙이기
n_outliers = len(X_outliers)    # outlier의 길이
ground_truth = np.ones(len(X), dtype=int)   # 1로 채워진 배열 생성
ground_truth[-n_outliers:] = -1     # ground_truth의 n_outliers부분 = -1

clf = LocalOutlierFactor(n_neighbors=20, contamination=0.1) # 이상치 감지 모델 생성
y_pred = clf.fit_predict(X)     # fit 예측하기
n_errors = (y_pred != ground_truth).sum()   # sum 구하기
X_scores = clf.negative_outlier_factor_ # 

plt.title("Local Outlier Factor (LOF)")   # 제목 붙이기
plt.scatter(X[:, 0], X[:, 1], color='k', s=3, label='Data points')  # 위 행렬로 산포 그래프 생성
radius = (X_scores.max() - X_scores) / (X_scores.max() - X_scores.min())    # 모서리 radius
plt.scatter(X[:, 0], X[:, 1],s=1000 * radius, edgecolors='r', facecolors='none', label='Outlier scores')  # 위 행렬로 산포 그래프 생성
plt.axis('tight')   # 중심선 지정
plt.xlim((-5, 5))   # x 좌표 축 값 범위
plt.ylim((-5, 5))   # y 좌표 축 값 범위
plt.xlabel("prediction eroors: %d" % (n_errors))    # x 라벨 지정
legend = plt.legend(loc = 'upper left') # 그래프에 범례 추가하기
legend.legendHandles[0]._sizes = [10]   # 범례 처리기1
legend.legendHandles[1]._sizes = [20]   # 범례 처리기2
plt.show() # 그래프 창 열기