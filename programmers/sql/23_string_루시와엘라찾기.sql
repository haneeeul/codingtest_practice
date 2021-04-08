SELECT ANIMAL_ID, NAME, SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE NAME REGEXP '^(Lucy|Ella|Pickle|Rogan|Sabrina|Mitty)$'
-- WHERE NAME REGEXP 'Lucy|Ella|Pickle|Rogan|Sabrina|Mitty' 은 틀리다
-- 정규표현식을 이용한 문자열 검색은 xxxLucyxxx와 같은 데이터도 포함할 수 있기 때문이다
ORDER BY ANIMAL_ID ASC;