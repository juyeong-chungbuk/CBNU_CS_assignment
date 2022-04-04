import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC

mushroom = pd.read_csv('버섯데이터 분류/mushrooms.csv', header=None)    # 버섯 데이터 셋 불러오기
print(mushroom.head(4)) # 받아온 데이터 4줄 출력

X = [ ] # 독 버섯인지 판별에 필요한 데이터
Y = [ ] # 독 버섯인지 판별한 데이터
for idx,row in mushroom[1:].iterrows(): # 
    Y.append(row.loc[0])    # 독 버섯인지 판별된 데이터 삽입
    row_x = [ ]
    for v in row.loc[1:]:   # 
        row_x.append(ord(v))    # 아스키 코드로 저장
    X.append(row_x) # 독 버섯인지 판별할 데이터 삽입

print('\n속성: \n', X[0:3]) # 속성 출력
print('\n부류: \n', Y[0:3]) # 부류 출력
x_train, x_test, y_train, y_test=train_test_split(X,Y,test_size=0.25)   # 데이터 분류하기

svc = SVC() # SVC 실행
svc.fit(x_train,y_train)    # 훈련데이터 fit

print('학습 데이터 정확도 : ', svc.score(x_train,y_train))  # 학습 데이터 정확도 출력
print('테스트 데이터 정확도 : ', svc.score(x_test,y_test))  # 테스트 데이터 정확도 출력