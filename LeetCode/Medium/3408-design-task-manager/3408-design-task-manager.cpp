class TaskManager {
public:
    map<int, int> taskToUser;
    map<int, int> taskToPriority;
    set<pair<int, int>> myTasks;

    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            taskToUser[tasks[i][1]] = tasks[i][0];
            taskToPriority[tasks[i][1]] = tasks[i][2];
            myTasks.insert({-tasks[i][2], -tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        myTasks.insert({-priority, -taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskToPriority[taskId];
        myTasks.erase({-oldPriority, -taskId});
        myTasks.insert({-newPriority, -taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskToPriority[taskId];
        myTasks.erase({-priority, -taskId});
    }
    
    int execTop() {
        if (myTasks.size() == 0) return -1;
        int topTask = myTasks.begin()->second * -1;
        myTasks.erase(myTasks.begin());
        return taskToUser[topTask];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */