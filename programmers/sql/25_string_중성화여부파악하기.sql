SELECT ANIMAL_ID, ANIMAL_NAME,
    IF(SEX_UPON_INTAKE LIKE '%Spayed%' OR SEX_UPON_INTAKE LIKE '%Neutered%', 'O', 'X') AS '중성화'
    -- IF(SEX_UPON_INTAKE REGEXP 'Neutered|Spayed', 'O' , 'X') AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID ASC;