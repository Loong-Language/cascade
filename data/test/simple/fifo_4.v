wire[4:0] rdata;
wire empty;

reg[5:0] sum = 0;

(*__file="data/test/simple/fifo_4.data"*)
Fifo#(1,4) fifo(
  .clock(clock.val),
  .rreq(!empty),
  .rdata(rdata),
  .empty(empty)
);

always @(posedge clock.val) begin
  if (empty) begin
    $write(sum + rdata);
    $finish;
  end else begin 
    sum <= sum + rdata;
  end
end
