from sklearn import datasets
import pandas as pd
iris = datasets.load_iris()

labels = pd.DataFrame(iris.target)  # DataFrame 타겟 구축
labels.columns=['labels']   # 라벨 컬럼
data = pd.DataFrame(iris.data)  # DataFrame 데이터 구축
data.columns=['Sepal length','Sepal width','Petal length','Petal width']    # 컬럼명 생성
data = pd.concat([data, labels],axis=1) # 배열 이어 붙이기
feature = data[['Sepal length','Sepal width','Petal length','Petal width']] # 데이터 생성

import matplotlib.pyplot as plt
from sklearn.manifold import TSNE

model = TSNE(learning_rate=100, perplexity=30)  # T-SNE 진행
transformed = model.fit_transform(feature)  # T-SNE 변환하기

xs = transformed[:,0]   # 변환 x좌표
ys = transformed[:,1]   # 변환 y좌표
plt.scatter(xs,ys,c=labels['labels'])   # 산포도 그리기

plt.show()  # 그래프 창 띄우기