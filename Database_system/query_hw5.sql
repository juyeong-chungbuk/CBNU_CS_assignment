USE world;

SELECT Name, Population FROM country WHERE Name='South Korea';

SELECT Name, Population FROM country WHERE Continent='Asia' ORDER BY Population DESC LIMIT 12;

SELECT Continent, COUNT(Name) AS cnt_countries FROM country GROUP BY Continent HAVING COUNT(Name) >= 5;
