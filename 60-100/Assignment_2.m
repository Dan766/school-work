|| Assignment 2 (60-100)
|| By Daniel Fontana

||Program 1
p1 = [[1,2], [2,3]]

||Program 2
p2 = p1!1

||Program 3
p3 n = map(^3) n 

||Program 4
p4 n = foldr(+) 0 n

||Program 5
p5 x y = x, if x >0
        = y, otherwise

||Program 6
p6 x y = x, if x!0 > y!0
        = y, otherwise

||Program 7
p7 0 = True
p7 n = p7 (n-3), if n > 0
     = False, otherwise

||Program 8
p8 [] y = False
p8 (x:xs) y = True, if x = y
            = p8 xs y, otherwise

||Program 9
p9 y =  (p4 . p3)y

||Program 10
p10 n m = [(x,y) | x <- n; y <- m; x > y]


