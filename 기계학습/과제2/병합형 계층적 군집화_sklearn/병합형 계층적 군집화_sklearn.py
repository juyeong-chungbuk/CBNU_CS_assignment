from sklearn.datasets import make_blobs
from sklearn.cluster import AgglomerativeClustering
import numpy as np
from matplotlib import pyplot as plt

# 표본 데이터 수 = 2000로 분류용 가상 데이터를 생성한다.
X, Y = make_blobs(n_samples=2000, n_features=2, centers=8, cluster_std=2.0)
plt.scatter(X[:,0], X[:,1], s=4)  # 위 행렬로 산포 그래프 생성
plt.title('Generated Data')   # 제목 붙이기
plt.show() # 그래프 창 열기

Z = AgglomerativeClustering(n_clusters=8, linkage='complete')   # 
P = Z.fit_predict(X)    # 예측 적용
colormap = np.array(['r', 'g', 'b', 'k', 'y', 'c', 'm', 'orange'])  # 
plt.scatter(X[:,0], X[:,1], s=4, c=colormap[P])  # 위 행렬로 산포 그래프 생성
plt.title('Clustering results')   # 제목 붙이기
plt.show() # 그래프 창 열기