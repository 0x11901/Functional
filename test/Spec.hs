main :: IO ()
main = putStrLn "Test suite not yet implemented"

replicate' :: Int -> a -> [a]
replicate' n x | n <= 0    = []
               | otherwise = x : replicate' (n - 1) x

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' _ [] = []
take' n (x : xs) | n <= 0    = []
                 | otherwise = x : take' (n - 1) xs
