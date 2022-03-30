from sklearn.decomposition import PCA
from sklearn import datasets
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import numpy as np

iris = datasets.load_iris() # 데이터 셋 로딩
print(list(iris.keys()))    # 키 출력
X = iris["data"[0:4]]   # iris데이터
label = iris["target"]  # iris 라벨

pca = PCA(n_components = 2) # PCA 진행
X2D = pca.fit_transform(X)  # 2차원으로 변환

for i, j in enumerate(np.unique(label)):    # label에 따라 반복
    plt.scatter(X2D[label == j, 0], X2D[label == j, 1], # 산포도 그래프에 그리기
                c = ListedColormap(('red', 'green', 'blue'))(i), label = j) # 컬러맵
plt.legend()    # 그래프 범례 그리기
plt.show()   # 그래프 창 띄우기
