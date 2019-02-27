module Main where
import           Data.List
import           Data.Maybe

main :: IO ()
main = putStrLn "no head feelings"

length' xs = sum [ 1 | _ <- xs ]

bmiTell :: Double -> Double -> String
bmiTell weight height
    | weight / height ^ 2 <= 18.5
    = "You're underweight, you emo, you!"
    | weight / height ^ 2 <= 25.0
    = "You're supposedly normal. Pffft, I bet you're ugly!"
    | weight / height ^ 2 <= 30.0
    = "You're fat! Lose some weight, fatty!"
    | otherwise
    = "You're a whale, congratulations!"

