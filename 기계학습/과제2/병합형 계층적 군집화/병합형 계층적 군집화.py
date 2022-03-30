from sklearn.datasets import make_blobs
from scipy.spatial.distance import pdist
from scipy.cluster.hierarchy import linkage
from scipy.cluster.hierarchy import dendrogram
import numpy as np
from matplotlib import pyplot as plt

# 표본 데이터 수 = 25로 가상 데이터를 생성한다.
X, Y = make_blobs(n_samples=25, n_features=2, centers=3, cluster_std=1.5)
colormap = np.array(['r', 'g', 'b'])    # 컬러 맵 생성
plt.scatter(X[:,0], X[:,1], c=colormap[Y])  # 위 행렬로 산포 그래프 생성
plt.title('Generated Data')   # 제목 붙이기
plt.show() # 그래프 창 열기

Xdist = pdist(X, metric='euclidean') # 거리 행렬 계산
Z = linkage(Xdist, method='ward') # ward 연결을 통한 계층적 군집화
Zd = dendrogram(Z)  # 계측 분석 시작
plt.title('Dendrogram')   # 제목 붙이기
plt.show() # 그래프 창 열기