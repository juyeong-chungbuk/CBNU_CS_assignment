import numpy as np
from matplotlib import pyplot as plt
from sklearn.datasets._samples_generator import make_blobs
from sklearn.cluster import KMeans

# 표본 데이터 수 = 300로 분류용 가상 데이터를 생성한다.
X, y = make_blobs(n_samples=300, centers=4, cluster_std=0.60, random_state=0)
plt.scatter(X[:,0], X[:,1], s=4)  # 위 행렬로 산포 그래프 생성
plt.title('Generated Data')   # 제목 붙이기
plt.show() # 그래프 창 열기

# 네 개의 클러스터로 데이터에 KMeans 알고리즘을 적용
kmeans = KMeans(n_clusters=4, init='k-means++', max_iter=300, n_init=10, random_state=0)
pred_y = kmeans.fit_predict(X)  # kmeans 예측 적용
colormap = np.array(['c', 'g', 'b', 'm'])   # 컬러맵 생성
plt.scatter(X[:,0], X[:,1], s=4, c=colormap[pred_y])   # 위 행렬로 산포 그래프 생성
plt.scatter(kmeans.cluster_centers_[:,0], kmeans.cluster_centers_[:,1], s=100, c='red')  # kmeans 클러스터 적용
plt.title('Clustering Results with Centers')   # 제목 붙이기
plt.show() # 그래프 창 열기