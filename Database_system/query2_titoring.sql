CREATE schema DBMS_tutoring;
USE DBMS_tutoring;

CREATE table TEACHER(
	TEACHER_NO INTEGER NOT NULL,
    NAME CHAR(10) NOT NULL,
    constraint TEACHER_PK primary key(TEACHER_NO)
);

create table STUDENT(
	STUDENT_NO INTEGER NOT NULL,
	NAME CHAR(10) NOT NULL,
    FNO INTEGER,
	TNO INTEGER,
    constraint FNO primary key(STUDENT_NO),
    FOREIGN KEY (TNO) REFERENCES TEACHER(TEACHER_NO) # 이 제약조건을 CONSTRAINT FK로 쓰겠다.
	#FNO는 자체릴레이션 pk을 참조
	#TNO는 TEACHER 테이블 pk를 참조
);

INSERT INTO TEACHER
VALUES  (1, '김선생'),
		(2, '박선생');

INSERT INTO STUDENT(STUDENT_NO, NAME, FNO, TNO)
VALUES  (1801, '박수학', NULL, 3),
		(1901, '한영어', 1801, 1),
        (1902, '김국어', 1901, 3),
        (1701, '최사회', 1902, 1),
        (1702, '신과학', 1701, 1),
        (1601, '윤역사', 1902, 3);

/*문제1 : 모든 선생님 출력*/

/*문제2 : 이름이 ~~학 또는 ~~어로 끝나고 선생님번호(TNO)가 2가 아닌 학생이름만 출력*/

/*문제3 : 학번, 이름, 선생님번호(TNO), A(=학번x선생님번호) 출력*/

SELECT * FROM TEACHER;
SELECT NAME FROM STUDENT WHERE (NAME LIKE '%학' or NAME LIKE '%어') and (TNO<>2);
SELECT STUDENT_NO, NAME, TNO, STUDENT_NO*TNO AS A FROM STUDENT; 

INSERT INTO STUDENT(STUDENT_NO, NAME, FNO, TNO)
VALUES  (2001, '강음악', 1801, 1);

/*문제1 : TNO가 1인 모든 STUDENT TABLE의 값들을 학번의 내림차순으로 정렬하여 출력*/
SELECT COUNT(*) FROM STUDENT WHERE TNO=1 ORDER BY STUDENT_NO DESC;

/*문제2 : STUDENT TABLE에 TNO와 TNO별 학번의 평균값, 학번의 최대값, 최소값을 출력              */
/*       학번의 평균값의 column명은 STDNO_AVG, 최대값은 STDNO_MAX, 최소값은 STDNO_MIN */
/*       이때, 그룹의 조건은 학번의 평균값이 1800 이상                            */
SELECT TNO, AVG(STUDENT_NO) AS STDNO_AVG, MAX(STUDENT_NO) AS STDNO_MAX, MIN(STUDENT_NO) AS STDNO_MIN
FROM STUDENT 
GROUP BY TNO
HAVING STDNO_AVG>=1800;

UPDATE TEACHER SET TEACHER_NO=3 WHERE TEACHER_NO=2;
DROP TABLE STUDENT;
create table STUDENT(
	STUDENT_NO INTEGER NOT NULL,
	NAME CHAR(10) NOT NULL,
    FNO INTEGER,
	TNO INTEGER,
    constraint FNO primary key(STUDENT_NO),
    FOREIGN KEY (TNO) REFERENCES TEACHER(TEACHER_NO)  on update cascade # 이 제약조건을 CONSTRAINT FK로 쓰겠다.
	#FNO는 자체릴레이션 pk을 참조
	#TNO는 TEACHER 테이블 pk를 참조
);

/*
1. CASCADE : 참조되는 테이블에서 데이터를 삭제하거나 수정하면, 참조하는 테이블에서도 삭제와 수정이 같이 이루어집니다.
2. SET NULL : 참조되는 테이블에서 데이터를 삭제하거나 수정하면, 참조하는 테이블의 데이터는 NULL로 변경됩니다.
3. NO ACTION : 참조되는 테이블에서 데이터를 삭제하거나 수정해도, 참조하는 테이블의 데이터는 변경되지 않습니다.
4. SET DEFAULT : 참조되는 테이블에서 데이터를 삭제하거나 수정하면, 참조하는 테이블의 데이터는 필드의 기본값으로 설정됩니다.
5. RESTRICT : 참조하는 테이블에 데이터가 남아 있으면, 참조되는 테이블의 데이터를 삭제하거나 수정할 수 없습니다.*/
