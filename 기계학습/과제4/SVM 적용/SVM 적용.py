from cvxopt import matrix, solvers, mul, spmatrix # 모듈 가져오기
import numpy as np

x = np.array([[1.,6.], [1.,8.],[4.,11.],[5.,2.],[7.,6.],[9.,3.]]) # 배열 생성
xt = np.transpose(x) # transpose하기
XXt = np.dot(x,xt) # x, xt로 점 구하기
y = np.array([[1.],[1.],[1.],[-1.],[-1.],[-1.]]) # 배열 생성
yt = np.transpose(y) # y를 transpose하기
yyt = np.dot(y,yt) # y, yt로 점 구하기
H = np.multiply(XXt, yyt) # XXt * yyt multiply구하기
H = matrix(H) # H를 행렬로 변환

f = matrix([-1., -1., -1., -1., -1., -1],(6,1), 'd') # f 행렬만들기
A = np.diag([-1.0, -1.0, -1.0, -1.0, -1.0, -1.0])    # A 행렬만들기
A = matrix(A)   # A행렬
a = matrix([0., 0., 0., 0., 0., 0.],(6,1), 'd') # a 행렬만들기
B = matrix([1, 1, 1, -1, -1, -1], (1,6),'d') # B 행렬만들기
b = matrix(0.0, (1,1), 'd') # b 행렬만들기

sol = solvers.qp(H, f, A, a, B, b) # solvers에서 qp실행
print('\n', 'alpha_1 = ',sol['x'][0])   # alpha_1부터 출력하기
print(' alpha_2 = ', sol['x'][1])
print(' alpha_3 = ', sol['x'][2])
print(' alpha_4 = ', sol['x'][3])
print(' alpha_5 = ', sol['x'][4])
print(' alpha_6 = ', sol['x'][5])