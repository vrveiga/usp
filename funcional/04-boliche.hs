main = do
  input <- getLine
  let jogadas = map read (words input)
  putStrLn $ show $ getPontos jogadas 0

getPontos [] _ = 0
getPontos [x] _ = x
getPontos (x1:x2:xs) bonus
  | x1 == 10 && bonus > 0  = 2*x1 + getPontos (x2:xs) (bonus+1)
  | x1 == 10 && bonus == 0 = x1 + getPontos (x2:xs) (bonus+2)
  | bonus == 0             = x1 + x2 + getPontos xs (getBonus x1 x2 bonus)
  | bonus == 1             = 2*x1 + x2 + getPontos xs (getBonus x1 x2 (bonus-1))
  | otherwise              = 2*x1 + 2*x2 + getPontos xs (getBonus x1 x2 (bonus-2))

getBonus x1 x2 bonus
  | x1 + x2 == 10 = bonus + 1
  | otherwise = bonus