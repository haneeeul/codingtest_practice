--CREATE TABLE ANIMAL_INS (
--    ANIMAL_ID VARCHAR(100) NOT NULL,
--    ANIMAL_TYPE VARCHAR(100) NOT NULL,
--    DATE_TIME DATETIME NOT NULL,
--    INTAKE_CONDITION VARCHAR(100) NOT NULL,
--    ANIMAL_NAME VARCHAR(100),
--    SEX_UPON_INTAKE VARCHAR(100) NOT NULL
--);

-- 예약어에 걸린다. (컬럼명 교체)
-- DATETIME -> DATE_TIME
-- NAME -> ANIMAL_NAME

/*
    본 문제는 Kaggle의 "Austin Animal Center Shelter Intakes and Outcomes"에서
    제공하는 데이터를 사용하였으며 ODbL의 적용을 받습니다.
*/

--INSERT INTO ANIMAL_INS (ANIMAL_ID, ANIMAL_TYPE, DATE_TIME, INTAKE_CONDITION, ANIMAL_NAME, SEX_UPON_INTAKE) VALUES ('A349996', 'Cat', 2018-01-22 14:32:00, 'Normal', 'Sugar', 'Neutered Male');

SELECT * FROM ANIMAL_INS
ORDER BY ANIMAL_ID ASC;