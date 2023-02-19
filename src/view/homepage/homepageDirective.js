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
                console.log($scope.items);
            } else {
                $scope.itemsRetrievingErrorMessage = result.data.error;
                $scope.itemsRetrievingError = true;
            }
        });

    }
});