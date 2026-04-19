(* statistics.ml *)
let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    (float_of_int ((List.nth sorted (n/2 - 1)) + (List.nth sorted (n/2)))) /. 2.0
  else
    float_of_int (List.nth sorted (n/2))

let mode lst =
  let count x = List.length (List.filter ((=) x) lst) in
  let max_count = List.fold_left (fun acc x -> max acc (count x)) 0 lst in
  List.filter (fun x -> count x = max_count) lst

let () =
  let data = [1;2;2;3;4;5;2] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode(s): ";
  List.iter (fun x -> Printf.printf "%d " x) (mode data);
  print_newline ()
