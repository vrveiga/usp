main = do
  la <- getLine
  lb <- getLine
  lc <- getLine
  let a = read la
      b = read lb
      c = read lc
      res = baskara a b c
  putStrLn $ show $ res

baskara a b c
  | delta < 0 = []
  | delta == 0 = [x]
  | otherwise = [x', x'']
    where
      delta = b ^ 2 - 4 * a * c
      x = (-b) / (2 * a)
      x' = (-b + sqrt delta) / (2 * a)
      x'' = (-b - sqrt delta) / (2 * a) 

sinal x
  | x < 0 = -1
  | x == 0 = 0
  | otherwise = 1

absoluto x
  | x >= 0 = x
  | otherwise = -x

somaPos [] = 0
somaPos (x:xs)
  | x > 0 = x + somaPos xs
  | otherwise = somaPos xs