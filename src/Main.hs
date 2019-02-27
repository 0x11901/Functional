module Main where
import           Data.List
import           Data.Maybe

main :: IO ()
main = putStrLn "no head feelings"

length' xs = sum [ 1 | _ <- xs ]

xxs =
    [ [1, 3, 5, 2, 3, 1, 2, 4, 5]
    , [1, 2, 3, 4, 5, 6, 7, 8, 9]
    , [1, 2, 4, 2, 1, 6, 3, 1, 3, 2, 3, 6]
    ]


