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
        
CREATE TABLE STUDENT(
STDNO int,
STDNAME varchar(15),
STDAGE int
);

INSERT INTO STUDENT
VALUES(1,'신주영',22,'여'),
(2,'김동용',24,'남'),
(3,'깜찍이',2,'여');

ALTER TABLE STUDENT
ADD COLUMN STDSEX varchar(5);

ALTER TABLE STUDENT
ADD STDNUM INT;

SELECT * FROM STUDENT;

ALTER TABLE STUDENT
MODIFY STDNUM INT;

ALTER TABLE STUDENT
CHANGE STDNUMBER STDNUM VARCHAR(15);

ALTER TABLE STUDENT
DROP COLUMN STDSEX;

TRUNCATE TABLE STUDENT;

ALTER TABLE STUDENT
MODIFY STDNUM INT NOT NULL;

CREATE TABLE teacher(
tNO int,
tNAME varchar(15),
tAGE int,
constraint cpk primary key (tNO)
);

ALTER TABLE TEACHER
DROP PRIMARY KEY;

USE WORLD;

/*a. Return all the attributes for cities using two conditions: the city’s first letter 
starts with ‘L’ (like London), and the city has over 1 million populations*/
SELECT *
FROM city
WHERE NAME LIKE 'L%' AND Population > 1000000;

/*b. Count the number of languages in the world.*/
SELECT Language, COUNT(Language)
FROM countrylanguage
GROUP BY Language;

SELECT COUNT(*)
FROM countrylanguage;

/*c. Which countries speak both Chinese and English?*/
SELECT Name
FROM country
WHERE Code IN (
SELECT c1.CountryCode
FROM countrylanguage AS c1 JOIN countrylanguage AS c2
ON c1.CountryCode=c2.CountryCode AND c1.language = 'English'
WHERE c2.Language = 'Chinese');

SELECT c1.CountryCode, c1.Language, c2.Language
FROM countrylanguage AS c1 JOIN countrylanguage AS c2
ON c1.CountryCode=c2.CountryCode AND c1.language = 'English'
WHERE c2.Language = 'Chinese';
