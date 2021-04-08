-- set(변수 사용하기) 또는 recursive 구문 사용하여 풀이

SET @HOUR_TIME = -1;

-- select 절에서 변수를 다시 세팅하는 방법 ':=' 사용하기
-- Mysql 메뉴얼에서는 권장하지 않는 방법이라고 한다.
SELECT @HOUR_TIME := @HOUR_TIME + 1 AS HOUR,
    (SELECT COUNT(*)
     FROM ANIMAL_OUTS
     WHERE HOUR(DATE_TIME) = @HOUR_TIME) AS ANIMAL_COUNT
FROM ANIMAL_OUTS
WHERE @HOUR_TIME < 23;


/* WITH RECURSIVE TIME AS (
    SELECT 0 AS h
    UNION ALL
    SELECT h + 1 FROM TIME WHERE h < 23
) -- count(datetime) 의 경우, count 값이 0인 경우는 출력되지 않는다. 따라서 반드시 출력하도록 시간 테이블을 하나 만들어서 조인한다.
SELECT h, COUNT(DATE_TIME)
FROM TIME
    LEFT OUTER JOIN ANIMAL_OUTS
    ON h = HOUR(DATE_TIME)
GROUP BY h
ORDER BY h ASC; */