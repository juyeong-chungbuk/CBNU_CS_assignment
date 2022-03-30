from matplotlib import pyplot as plt
from sklearn.datasets._samples_generator import make_blobs
from sklearn.cluster import KMeans

# 표본 데이터 수 = 300로 분류용 가상 데이터를 생성한다.
X, y = make_blobs(n_samples=300, centers=4, cluster_std=0.60, random_state=0)
plt.scatter(X[:,0], X[:,1]) # 위 행렬로 산포 그래프 생성
plt.show() # 그래프 창 열기

SSEs = []
for i in range(1, 11):  # 11까지 반복
    kmeans = KMeans(n_clusters=i, init='k-means++', max_iter=300, n_init= 10, random_state=0)   # KMeans Elbow
    kmeans.fit_predict(X)   # kmeans예측하기
    SSEs.append(kmeans.inertia_) # SSE값 저장
    
plt.plot(range(1,11), SSEs, marker='o') # plot적용
plt.show() # 그래프 창 열기