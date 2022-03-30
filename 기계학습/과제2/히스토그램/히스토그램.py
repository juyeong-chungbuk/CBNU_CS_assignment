import numpy as np
from matplotlib import pyplot as plt

X1 = np.random.randn(1000)  # 균일 분포에서 난수 매트릭스 배열 생성
X2 = 10 + np.random.randn(1000) # 균일 분포에서 난수 매트릭스 배열 생성

plt.figure(figsize=(10,6))  # figure 생성
plt.hist(X1, bins=20, alpha=0.4)    # 히스토그램 막대 그리기
plt.hist(X2, bins=20, alpha=0.4)    # 히스토그램 막대 그리기
plt.show() # 그래프 창 열기