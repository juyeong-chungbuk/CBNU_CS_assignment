import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm
from sklearn import mixture

n_samples = 600 # 샘플 600개
np.random.seed(0) # 랜덤 시드
shifted_gaussian = np.random.randn(n_samples, 2) + np.array([15, 30])   # 혼성 가우시안 랜덤
C1 = np.array([[0., -0.7], [1.5, .7]])  # 맵 생성
stretched_gaussian1 = np.dot(np.random.randn(n_samples, 2), C1)+ np.array([-5, -25])    # 가우시안1 점 그리기
C2 = np.array([[0.5, 1.7], [-1.5, 0.5]])    # 맵 생성
stretched_gaussian2 = np.dot(np.random.randn(n_samples, 2), C2)+ np.array([-15, 5])     # 가우시안2 점 그리기
X_train = np.vstack([shifted_gaussian, stretched_gaussian1, stretched_gaussian2])   # 넘파이 배열 결합
plt.xlim(-50,50)    # 좌표축 값 범위
plt.ylim(-50,50)    # 좌표축 값 범위
plt.scatter(X_train[:, 0], X_train[:, 1], .8, color='r') # 위 행렬로 산포 그래프 생성
plt.show() # 그래프 창 열기

clf = mixture.GaussianMixture(n_components=3, covariance_type='full')   # 혼성 가우시안 실시
clf.fit(X_train)    # 훈련 fit
x = np.linspace(-50., 50.)  # 간격 간 벡터 생성
y = np.linspace(-50., 50.)  # 간격 간 벡터 생성
X, Y = np.meshgrid(x,y) # 2차원 그리드 생성
XX = np.array([X.ravel(), Y.ravel()]).T # 
Z = -clf.score_samples(XX)  # 샘플 점수 매기기
Z = Z.reshape(X.shape)  # reshape하기

plt.contour(X, Y, Z, norm=LogNorm(vmin=1.0, vmax=1000.0), levels=np.logspace(0, 3, 10)) # 윤곽 그리기
plt.scatter(X_train[:, 0], X_train[:, 1], .8, color='r') # 위 행렬로 산포 그래프 생성
plt.title('Mixture of Gaussians')   # 제목 붙이기
plt.show() # 그래프 창 열기