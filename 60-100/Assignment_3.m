p1 = ["hello","goodbye"]
p2 = p1!1

p3 = map (3:)

p4 = foldr my_op 1 
    where my_op (a,b) rest = a * rest
	
p5 n m = "lengths greater than 2", if #n > 2 & #m > 2
       = "not greater than 2", otherwise

p6 (x:xs) (y:ys) = (x:xs), if x > y 
                 = (y:ys), if y >= x
				 
p7 0 = [0]
p7 n = n:p7 (n-1)

p8 [] = [] 
p8 (x:xs) = x + 3 : p8 xs 

p9 = square . sum . map square 

p10 n = [x!0 | x <- n] 

|| 2.1 [‘t’,‘x’]

|| 2.1 [(3,'k')]



