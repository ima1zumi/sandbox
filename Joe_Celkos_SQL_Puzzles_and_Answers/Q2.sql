CREATE TABLE Absenteeism (
  emp_id INTEGER
    NOT NULL
    REFERENCES Personnel (emp_id),
  absent_date DATE
    NOT NULL,
  reason_code CHAR(40)
    REFERENCES ExcuseList (reason_code),
  severity_points INTEGER
    NOT NULL
    CHECK (severty_points BETWEEN 0 AND 4),
  PRIMARY KEY (emp_id, absent_date)
)

-- Answer

DELETE P
FROM Personnel as P
JOIN Absenteeism
  ON P.emp_id = P.id
WHERE P.id IN (
  SELECT
    emp_id
  FROM
    Absenteeism
  GROUP BY emp_id
  HAVING SUM(severty_points) > 39
)

/*
UPDATEの方はUPDATEでやるのがいいとは思えない. 最初から正しい値を入れておけばいいだけだと思う
INSERT前にSELECTして前日に欠勤があればseverty_pointsを0でINSERT
それでもUPDATEでしかできないとしたら？という問題なのか


/*
Example 1
*/
