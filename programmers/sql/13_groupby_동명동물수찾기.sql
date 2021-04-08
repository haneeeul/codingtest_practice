-- group by 절은 null 값도 따로 column으로 만든다.
-- 따라서 이름이 없는 동물은 'null' column에 들어간다.

-- group by 절에 있는 column 명은 select 절에 반드시 등장해야한다.

SELECT ANIMAL_NAME, COUNT(ANIMAL_NAME) AS NAME_COUNT
FROM ANIMAL_INS
GROUP BY ANIMAL_NAME
HAVING COUNT(ANIMAL_NAME) >= 2
ORDER BY ANIMAL_NAME;