# Write your MySQL query statement below
select e.name as Employee
from Employee e
JOIN Employee m
on e.managerId=m.id
where e.salary>m.salary
-- SELECT e.name AS Employee
-- FROM Employee e
-- JOIN Employee m
-- ON e.managerId = m.id
-- WHERE e.salary > m.salary;