# Write your MySQL query statement below
select * from cinema where id%2=1 and LOCATE('boring',description)=0 order by rating desc
