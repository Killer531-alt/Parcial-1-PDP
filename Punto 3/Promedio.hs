promedio :: [Double] -> Double
promedio xs = sum xs / fromIntegral (length xs)

main :: IO ()
main = do
    let notas = [4.5, 3.8, 4.9, 3.7]
    putStrLn ("Notas: " ++ show notas)
    putStrLn ("Promedio: " ++ show (promedio notas))
