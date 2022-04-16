import pandas as pd # 모듈 가져오기
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler

pdiabetes = pd.read_csv('당뇨병 판정/diabetes.csv', header=None) # 당뇨병 데이터 가져오기
print(pdiabetes[0:5]) # 가져온 데이터 출력하기

x = pdiabetes.iloc[1:,8:] # 당뇨병 데이터의 iloc하기
y = pdiabetes.iloc[1:,8:].values.flatten() # 당뇨병 데이터의 iloc한 값 평탄화
print('x shape: ', x.shape, 'y shape: ', y.shape) # 출력하기

x_train, x_test, y_train, y_test = train_test_split(x, y, random_state=0) # 학습, 테스트로 나누어 데이터 분리
std_scl = StandardScaler() # StandardScaler 실행하기
std_scl.fit(x_train) # x_train fit함수

x_train = std_scl.transform(x_train) # x_train를 std_scl로 변형하기
x_test = std_scl.transform(x_test) # x_test를 std_scl로 변형하기

svc = SVC(kernel='rbf') # SVC실행
svc.fit(x_train, y_train) # x_train, y_train로 fit

print('학습 데이터 정확도 : ', svc.score(x_train, y_train)) # 학습 데이터 정확도 출력하기
print('테스트 데이터 정확도 : ', svc.score(x_test, y_test)) # 테스트 데이터 정확도 출력하기
