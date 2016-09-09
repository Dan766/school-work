|| 60-100 Individual Assignment #1
|| By Daniel Fontana

|| Program 1
p1 = 18

|| Program 2
p2 = "Daniel Fontana"

|| Program 2
p3 n = n*2

|| Program 4
p4 n m = n, if n > m
       = m, if m > n
       = error "Numbers are Equal", if n = m 

|| Program 5
p5 x = map (*2) x

|| Program 6
p6 x = x!0

|| Program 7
p7 x = foldr (*) 1 x

|| Program 8
p8 0 = 1
p8 x = x * p8 (x-1) 

|| Program 9
p9 x y = x -- (x--y)

|| Program 10
p10 = foldr rev []
         where rev a x = x ++ [a]


|| Program 11
p11 p = p11 (p -2), if p > 1
      = True, if p = 0
      = False, otherwise 

|| Program 12
p12 [] = 0
p12 ((x,y):list) = x + p12 (list)

