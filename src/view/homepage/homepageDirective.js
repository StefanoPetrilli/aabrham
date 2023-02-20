var aabrham = angular.module('aabrham', []);

aabrham.controller('HomepageController', function HomepageController($scope, $http) {

    $scope.init = function () {
        $scope.getItems();
    };

    $scope.signout = function () {
        $http.get("/homepage/api/signout").then(function (result) {
            result.data.result ?
                window.location.href = "/" :
                $scope.failedLogin = true;
        });
    }

    $scope.insertItem = function (itemName) {
        let message = {
            itemName: itemName
        };

        $http.post("/api/item/insert", JSON.stringify(message)).then(function (result) {
            if (result.data.result) $scope.getItems();
            else {
                $scope.errorMessage = result.data.error;
                $scope.insertError = true;
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

    var myfunc = setInterval(function () {
        var now = new Date().getTime();

        for (var i in $scope.items) {
            var timeleft = $scope.items[i]['time'] - now;
            if (timeleft > 0) {
                var days = Math.floor(timeleft / (1000 * 60 * 60 * 24));
                var hours = Math.floor((timeleft % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
                var minutes = Math.floor((timeleft % (1000 * 60 * 60)) / (1000 * 60));
                var seconds = Math.floor((timeleft % (1000 * 60)) / 1000);
                $scope.items[i]['timeLeft'] = days + "d " + hours + "h " + minutes + "m " + seconds + "s ";
            } else {
                $scope.items[i]['timeLeft'] = false;
            }
            console.log($scope.items);
            $scope.$apply();
        }
    }, 1000)
});