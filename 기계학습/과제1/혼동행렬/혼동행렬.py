import numpy as np
from sklearn.metrics import accuracy_score, confusion_matrix    # 분류 모형을 만들기 위한 패키지
y_true = ["positive", "negative", "negative","positive","positive","positive","negative"]   # 정답인 y값 정의하기 - positive: 양성, negative: 음성
y_pred = ["positive", "negative", "positive","positive","negative","positive","positive"]   # 분류모형 예측 값인 y값 정의하기

cm = confusion_matrix(y_true, y_pred)   # 위 변수로 분류 결과표 만들기
print('confusion matrix')   # 제목 출력
print(cm)   # 분류 결과표 출력
a = accuracy_score(y_true, y_pred)  # 실제 값과 예측 값 사이 정확도 계산하기
print('accuracy: ', a)  # 정확도 출력하기

#           예측 양성   예측 음성
# 실제 양성     TP         FN
# 실제 음성     FP         TN
y_pred = [0, 5, 2, 4]   # 예측 값 대입
y_true = [0, 1, 2, 3]   # 실제 값 대입
a = accuracy_score(y_true, y_pred)  # 실제 값과 예측 값 사이 정확도 계산하기
print('accuracy: ', a)  # 정확도 출력하기