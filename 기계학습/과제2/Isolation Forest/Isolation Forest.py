import numpy as np
import pandas as pd
from sklearn.ensemble import IsolationForest
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

n_samples = 500 # 포본 데이터 500개
outliers_fraction = 0.05    # 
n_outliers = int(outliers_fraction * n_samples) # outliers 추출
n_inliers = n_samples - n_outliers  # inliers 추출
blobs_params = dict(random_state=0, n_samples=n_inliers, n_features=2)  # dict로 만들기
X = make_blobs(centers=[[0, 0], [4, 3]],    # 가상 데이터 생ㅇ성
               cluster_std=0.5,
               **blobs_params)[0]
rng = np.random.RandomState(42) # 랜덤
X = np.concatenate([X, rng.uniform(low=-6, high=6, size=(n_outliers, 2))], axis=0)  # concatenate 진행

iForest = IsolationForest(n_estimators=20, verbose=2)   # IsolationForest 시작
iForest.fit(X)  # fit

pred = iForest.predict(X)   # iForest 예측 시작하기
plt.scatter(X[:, 0], X[:, 1], c=pred, cmap='RdBu')  # 위 행렬로 산포 그래프 생성
plt.show() # 그래프 창 열기

pred_scores = -1 * iForest.score_samples(X) # 예측 점수 계산
plt.scatter(X[:, 0], X[:, 1], c=pred_scores, cmap='RdBu')  # 위 행렬로 산포 그래프 생성
plt.colorbar(label='Simplified Anomaly Score')
plt.show() # 그래프 창 열기