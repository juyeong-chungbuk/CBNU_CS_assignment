from sklearn.datasets import make_moons
from sklearn.cluster import DBSCAN
import numpy as np
from matplotlib import pyplot as plt
# 표본 데이터 수 = 1000로 가상 데이터 생성
X, Y = make_moons(n_samples=1000, noise=0.05)

plt.title('Half moons')   # 제목 붙이기
plt.scatter(X[:,0], X[:,1]) # 위 행렬로 산포 그래프 생성
plt.show()  # 그래프 창 그리기
dbs = DBSCAN(eps=0.1)   # DBSCAN 군집화
Z = dbs.fit_predict(X)  # fit 예측하기

colormap = np.array(['r', 'b'])     # 컬러맵 생성
plt.scatter(X[:,0], X[:,1], c=colormap[Z])  # 위 행렬로 산포 그래프 생성
plt.title('DBSCAN for half moons')   # 제목 붙이기
plt.show()  # 그래프 창 열기 