(* Function to calculate mean *)
let mean numbers =
  let sum = List.fold_left ( + ) 0 numbers in
  float_of_int sum /. float_of_int (List.length numbers)

(* Function to calculate median *)
let median numbers =
  let sorted = List.sort compare numbers in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted ((len / 2) - 1) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int mid1 +. float_of_int mid2) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

(* Function to calculate mode *)
let mode numbers =
  let rec count_occurrences acc = function
    | [] -> acc
    | x :: xs ->
      let current_count = List.assoc_opt x acc |> Option.value ~default:0 in
      count_occurrences ((x, current_count + 1) :: acc) xs
  in
  let counts = count_occurrences [] numbers in
  let max_count = List.fold_left (fun max (_, count) -> if count > max then count else max) 0 counts in
  List.fold_left
    (fun modes (num, count) -> if count = max_count then num :: modes else modes)
    [] counts

(* Main function to demonstrate usage *)
let () =
  let numbers = [1; 2; 3; 4; 5; 5; 6; 7; 8; 9] in
  Printf.printf "Numbers: ";
  List.iter (Printf.printf "%d ") numbers;
  Printf.printf "\n";
  
  Printf.printf "Mean: %.2f\n" (mean numbers);
  Printf.printf "Median: %.2f\n" (median numbers);
  
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (mode numbers);
  Printf.printf "\n" 