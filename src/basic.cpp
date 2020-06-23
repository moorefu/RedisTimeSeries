#include "../deps/benchmark/include/benchmark/benchmark.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "generic_chunk.h"
#include "compressed_chunk.h"
#ifdef __cplusplus
}
#endif

static void BM_StringCreation(benchmark::State& state) {
  Chunk_t *chunk = Compressed_NewChunk(256);
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);
BENCHMARK(BM_StringCopy)->Threads(6);
BENCHMARK(BM_StringCopy)->ThreadRange(1, 1024);

BENCHMARK_MAIN();