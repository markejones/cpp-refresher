#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int mutuallyExclusiveResource = 0;

void updateResource() {
  const std::lock_guard<std::mutex> lock(m);
  std::cout << "Thread " << std::this_thread::get_id() << std::endl;
  std::cout << "The mutually exclusive resource is being updated from: " << mutuallyExclusiveResource << " to " << mutuallyExclusiveResource + 1 << std::endl;
  mutuallyExclusiveResource += 1;
  std::cout << "===\n";
}

int main() {
  std::thread mainThread(updateResource);
  std::thread uiThread(updateResource);
  std::thread networkThread(updateResource);

  mainThread.join();
  uiThread.join();
  networkThread.join();
  return 0;
}
