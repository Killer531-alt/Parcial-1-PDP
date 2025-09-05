import Data.List (sortBy)
import Data.Ord (comparing)

estudiantes :: [(String, Int)]
estudiantes = [("Andres", 70), ("Ana", 90), ("Juan", 85), ("Lucas", 95)]

ordenados :: [(String, Int)]
ordenados = sortBy (\(n1, nota1) (n2, nota2) ->
                      compare nota2 nota1 <> compare n1 n2) estudiantes

main :: IO ()
main = mapM_ print ordenados
