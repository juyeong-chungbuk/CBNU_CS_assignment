CREATE DATABASE DBTEST;
USE DBTEST;

CREATE TABLE DEPARTMENT(
DEPTNO int,
DEPTNAME varchar(15),
FLOOR int,
CONSTRAINT PK_D PRIMARY KEY DEPARTMENT(DEPTNO)
);

CREATE TABLE EMPLOYEE(
EMPNO int,
EMPNAME varchar(15),
DNO int,
CONSTRAINT PK_E PRIMARY KEY EMPLOYEE(EMPNO),
CONSTRAINT FK_D FOREIGN KEY (DNO) REFERENCES DEPARTMENT(DEPTNO)
);

INSERT INTO DEPARTMENT
VALUE(1,'영업',8),
(2,'기획',10),
(3,'개발',9);

INSERT INTO EMPLOYEE
VALUE(2106,'김창섭',2),
(3426,'박영권',3),
(3011,'이수민',1),
(1003,'조민희',1),
(3427,'최종철',3);

SELECT *
FROM EMPLOYEE E
WHERE EXISTS
	(SELECT *
	FROM DEPARTMENT D
	WHERE E.DNO=D.DEPTNO
		AND (DEPTNAME='영업' OR DEPTNAME='개발'));
        
SELECT *
FROM EMPLOYEE
WHERE DNO IN (
	SELECT DEPTNO
    	FROM DEPARTMENT
    	WHERE DEPTNAME='영업' OR DEPTNAME='개발');
        

-- strong entity
EMPLOYEE(Empno, Title, Empname, Salary, City, Ku, Dong)
DEPARTMENT(Deptno, Depname, Floor)
PROJECT(Projno, Projname, Budget)
SUPPLIER(Suppno, Suppname, Credit)
PART(Partno, Partname, Price)

-- weak entity
DEPENDENT(Empno, Depname, Sex)

-- 1:1 Cardinality
PROJECT(Projno, Empno, Projname, Budget, Manager, StartDate)

-- 1:N Cardinality
DEPENDENT(Depname, Sex, Empno)
EMPLOYEE(Empno, Title, Empname, Salary, City, Ku, Dong, Dno)
PART(Partno, Partname, Price, Subpartno)

-- N:M Caldinality
WORKS_FOR(Empno, Projno, Duration, Responsibility)
SUPPLIES(Projno, Partno, Quantity)

-- ternary Caldinality
SUPPLIES(Projno, Partno, Suppno, Quantity)

-- 다치 속성
PROJ_LOC(Projno, Location)

-- 최종
EMPLOYEE(Empno, Title, Empname, Salary, City, Ku, Dong, Dno)
DEPARTMENT(Deptno, Depname, Floor)
PROJECT(Projno, Empno, Projname, Budget, Manager, StartDate)
SUPPLIER(Suppno, Suppname, Credit)
DEPENDENT(Depname, Sex, Empno)
PART(Partno, Partname, Price, Subpartno)
WORKS_FOR(Empno, Projno, Duration, Responsibility)
SUPPLIES(Projno, Partno, Suppno, Quantity)
PROJ_LOC(Projno, Location)