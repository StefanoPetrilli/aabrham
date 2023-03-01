var aabrham = angular.module('aabrham', []);

aabrham.controller('HomepageController', function HomepageController($scope, $http) {

    $scope.formContent = {};

    $scope.init = function () {
        $scope.getItems();
        $scope.getQuestions();
    };

    $scope.signout = function () {
        $http.get("/homepage/api/signout").then(function (result) {
            result.data.result ? window.location.href = "/" : $scope.failedLogin = true;
        });
    }

    $scope.insertItem = function (formContent) {
        $http.post("/api/item/insert", JSON.stringify(formContent)).then(function (result) {
            if (result.data.result) $scope.getItems(); else {
                $scope.errorMessage = result.data.error;
                $scope.insertError = true;
            }
        });
    }

    $scope.getQuestions = function () {
        $http.get("/api/question/get").then(function (result) {
            if (result.data.result) {
                $scope.questions = result.data.questions;
            } else {
                $scope.questionsRetrievingErrorMessage = result.data.error;
                $scope.questionsRetrievingError = true;
            }
        });
    }

    $scope.getItems = function () {
        $http.get("/api/item/get").then(function (result) {
            if (result.data.result) {
                $scope.items = result.data.items;
            } else {
                $scope.itemsRetrievingErrorMessage = result.data.error;
                $scope.itemsRetrievingError = true;
            }
        });
    }

    const millisecondsInSecond = 1000;
    const millisecondsInMinute = millisecondsInSecond * 60;
    const millisecondsInHour = millisecondsInMinute * 60;
    const millisecondsInDay = millisecondsInHour * 24;

    const getDaysLeft = (milliseconds) => Math.floor(milliseconds / (millisecondsInDay))

    const getHoursLeft = (milliseconds) => Math.floor(milliseconds % (millisecondsInDay)) / (millisecondsInHour);

    const getMinutesLeft = (milliseconds) => Math.floor((milliseconds % (millisecondsInHour)) / (millisecondsInMinute));

    const getSecondsLeft = (milliseconds) => Math.floor((milliseconds % (millisecondsInMinute)) / millisecondsInSecond);


    setInterval(() => {
        const now = new Date().getTime();

        for (const i in $scope.items) {
            const timeLeft = $scope.items[i]['time'] - now;
            if (timeLeft > 0)
                $scope.items[i]['timeLeft'] =
                    getDaysLeft(timeLeft) + "d " +
                    getDaysLeft(timeLeft) + "h " +
                    getMinutesLeft(timeLeft) + "m " +
                    getSecondsLeft(timeLeft) + "s ";
            else
                $scope.items[i]['timeLeft'] = false;

            $scope.$apply();
        }
    }, millisecondsInSecond);
});