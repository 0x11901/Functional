main :: IO ()
main = putStrLn "Test suite not yet implemented"

replicate' :: Int -> a -> [a]
replicate' n x | n <= 0    = []
               | otherwise = x : replicate' (n - 1) x

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' _ [] = []
take' n (x : xs) | n <= 0    = []
                 | otherwise = x : take' (n - 1) xs

reverse' :: [a] -> [a]
reverse' []       = []
reverse' (x : xs) = reverse' xs ++ [x]

zip' :: [a] -> [b] -> [(a, b)]
zip' []       _        = []
zip' _        []       = []
zip' (x : xs) (y : ys) = (x, y) : zip' xs ys

elem' :: (Eq a) => a -> [a] -> Bool
elem' _ [] = False
elem' a (x : xs) | a == x    = True
                 | otherwise = a `elem'` xs

quicksort :: (Ord a) => [a] -> [a]
quicksort []       = []
quicksort (x : xs) = quicksort smallerOrEqual ++ [x] ++ quicksort larger
 where
  smallerOrEqual = filter (<= x) xs
  larger         = filter (> x) xs

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ []       _        = []
zipWith' _ _        []       = []
zipWith' f (x : xs) (y : ys) = f x y : zipWith' f xs ys

elem'' :: (Eq a) => a -> [a] -> Bool
-- elem'' y ys = foldr (\x acc -> if x == y then True else acc) False ys
elem'' y = foldr (\x acc -> (x == y) || acc) False

oddSquareSum :: Integer
oddSquareSum = sum . takeWhile (< 10000) . filter odd $ map (^ 2) $ [1 ..]
