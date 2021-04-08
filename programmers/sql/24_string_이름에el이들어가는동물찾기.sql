SELECT ANIMAL_ID, ANIMAL_NAME
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = 'Dog' AND (ANIMAL_NAME LIKE '%el%'
                               OR ANIMAL_NAME LIKE '%EL%'
                               OR ANIMAL_NAME LIKE '%El%'
                               OR ANIMAL_NAME LIKE '%eL%')
ORDER BY ANIMAL_NAME ASC;

-- mysql 은 like 로 문자열 검사 시에 대소문자를 구분하지 않는다.
-- 따라서 아래도 정답으로 인정된다.
-- SELECT ANIMAL_ID, ANIMAL_NAME
-- FROM ANIMAL_INS
-- WHERE ANIMAL_TYPE = 'Dog' AND ANIMAL_NAME LIKE '%el%'
-- ORDER BY ANIMAL_NAME ASC;

-- 대소문자를 구분하고 싶다면
BINARY(ANIMAL_NAME) LIKE '%el%'

-- SELECT ANIMAL_ID, ANIMAL_NAME
-- FROM ANIMAL_INS
-- WHERE ANIMAL_TYPE = 'Dog' AND ANIMAL_NAME REGEXP 'EL|El|eL|el'
-- ORDER BY ANIMAL_NAME ASC;