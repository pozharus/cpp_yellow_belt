#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <iterator>
using namespace std;
// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return persons_tasks.find(person)->second;
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++persons_tasks[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo updated_tasks;
        TasksInfo old_tasks;
        if(persons_tasks.count(person)) {
            TasksInfo buffer;
            buffer = persons_tasks.find(person)->second;

            /*
            for(auto& item : buffer) {
                if(task_count > 0) {
                    while(item.second > 0 and task_count > 0) {
                            item.second--;
                            task_count--;
                        }
                    continue;
                }
            }
             */

            cout << buffer[TaskStatus::NEW] << " new tasks" <<
             ", " << buffer[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
             ", " << buffer[TaskStatus::TESTING] << " tasks are being tested" <<
             ", " << buffer[TaskStatus::DONE] << " tasks are done" << endl;


            return tie(updated_tasks,old_tasks);
        } else {
            updated_tasks.clear();
            old_tasks.clear();
            return tie(updated_tasks,old_tasks);
        }
    }
private:
    map<string, TasksInfo>persons_tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    /*
    tasks.AddNewTask("Yaroslav");
    tasks.AddNewTask("Yaroslav");
    tasks.AddNewTask("Yaroslav");
    tasks.AddNewTask("Yaroslav");
    */
    tasks.AddNewTask("Ivan");
    tasks.AddNewTask("Ivan");
    tasks.AddNewTask("Ivan");
    tasks.AddNewTask("Ivan");
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
    tasks.PerformPersonTasks("Ivan",1);
    return 0;
}
