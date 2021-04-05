-- NAME -> ANIMAL_NAME
-- DATETIME -> DATE_TIME

/*

    COUNT(*) -- NULL 을 포함하여 세기
    COUNT(column name) -- NULL 을 제외하고 세기
    COUNT(DISTINCT(column name)) -- 중복 삭제, NULL 을 제외하고 세기

*/

/*
SELECT COUNT(DISTINCT(ANIMAL_NAME)) AS count_animals_name FROM ANIMAL_INS;
*/

SELECT COUNT(DISTINCT ANIMAL_NAME) AS 'count_animals_name' FROM ANIMAL_INS
WHERE ANIMAL_NAME IS NOT NULL;